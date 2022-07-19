package controller;

import domain.Seat;
import domain.Subscription;
import domain.User;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import service.Service;

import java.io.IOException;
import java.time.LocalDate;
import java.util.Map;
import java.util.stream.Collectors;

public class ViewSubscriptionsController {
    public Button buttonSubscriptions;
    public TableView<Subscription> tableViewSubscriptions;
    public TableColumn<Subscription, Integer> daysColumn;
    public TableColumn<Subscription, Integer> priceColumn;
    public Label paymentLabel;
    public ComboBox<String> paymentComboBox;
    public Button buyButton;
    public AnchorPane mainPane;

    ObservableList<Subscription> modelSubscriptions = FXCollections.observableArrayList();

    public Service service;
    private User user;

    public void settings(Service service, User user) throws IOException {
        this.service = service;
        this.user = user;
        setSubscriptions();
        setComboBox();
    }

    private void setComboBox() {
        ObservableList<String> paymentObservableList = FXCollections.observableArrayList();
        paymentObservableList.add("Cash");
        paymentObservableList.add("Card");
        paymentComboBox.setItems(paymentObservableList);
    }

    private void setSubscriptions() {
        modelSubscriptions.clear();
        modelSubscriptions.add(new Subscription(user, 100, 5, false));
        modelSubscriptions.add(new Subscription(user, 150, 10, false));
        modelSubscriptions.add(new Subscription(user, 200, 20, false));
        modelSubscriptions.add(new Subscription(user, 450, 50, false));
        daysColumn.setCellValueFactory(new PropertyValueFactory<>("showsLeft"));
        priceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        tableViewSubscriptions.setItems(modelSubscriptions);
    }

    public void onSubscriptionsClick(ActionEvent actionEvent) {
        if(buttonSubscriptions.getText().equals("Your subscriptions")){
            buttonSubscriptions.setText("Buy subscriptions");
            buyButton.setText("Delete Subscription");
            paymentComboBox.setVisible(false);
            paymentLabel.setVisible(false);

            modelSubscriptions.clear();
            modelSubscriptions.setAll(service.findAllSubscriptionsForUser(user));
            daysColumn.setCellValueFactory(new PropertyValueFactory<>("showsLeft"));
            priceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
            tableViewSubscriptions.setItems(modelSubscriptions);
        } else {
            buttonSubscriptions.setText("Your subscriptions");
            buyButton.setText("Buy Subscription");
            paymentComboBox.setVisible(true);
            paymentLabel.setVisible(true);

            setSubscriptions();
        }

    }

    public void onBuyClick(ActionEvent actionEvent) throws IOException {
        if(buyButton.getText().equals("Buy Subscription")) {
            String paymentMethod = (String) paymentComboBox.getValue();
            Subscription subscription = tableViewSubscriptions.getSelectionModel().getSelectedItem();
            if (paymentMethod.equals("Card")) {
                FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("payment-card-view.fxml"));
                AnchorPane dashboard = fxmlLoader.load();
                Node oldRegion = mainPane.getChildren().set(0, dashboard);
                Map<Object, Object> properties = dashboard.getProperties();
                oldRegion.getProperties().forEach(properties::putIfAbsent);
                PaymentCardController controller = fxmlLoader.getController();
                controller.settings(service, user, null, null, subscription);
                mainPane.getChildren().setAll(dashboard);
            } else {
                MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success",
                        "\nCome to the theatre to pay your subscription." +
                                "\nPrice to pay:" + subscription.getPrice() + " RON");
                service.saveSubscription(subscription);
            }
        } else {
            Subscription subscription = tableViewSubscriptions.getSelectionModel().getSelectedItem();
            System.out.println(subscription);
            System.out.println(subscription.getId());
            service.deleteSubscription(subscription);
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Delete", "Reservation deleted!");
            modelSubscriptions.clear();
            modelSubscriptions.setAll(service.findAllSubscriptionsForUser(user));
            daysColumn.setCellValueFactory(new PropertyValueFactory<>("showsLeft"));
            priceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
            tableViewSubscriptions.setItems(modelSubscriptions);
        }
    }
}
