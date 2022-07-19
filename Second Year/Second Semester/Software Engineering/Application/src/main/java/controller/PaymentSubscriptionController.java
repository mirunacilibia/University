package controller;

import domain.Seat;
import domain.Show;
import domain.Subscription;
import domain.User;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import service.Service;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class PaymentSubscriptionController {
    public AnchorPane mainPane;
    public TableView<Subscription> tableViewSubscriptions;
    public TableColumn<Subscription, Integer> daysColumn;
    public TableColumn<Subscription, Integer> priceColumn;
    public TableColumn<Subscription, Integer> idColumn;

    ObservableList<Subscription> modelSubscriptions = FXCollections.observableArrayList();

    public Service service;
    private User user;
    private Show show;
    private HashMap<Integer, Seat> chosenSeats;

    public void settings(Service service, User user, Show show, HashMap<Integer, Seat> chosenSeats) throws IOException {
        this.service = service;
        this.user = user;
        this.show = show;
        this.chosenSeats = chosenSeats;
        setSubscriptions();
    }

    private void setSubscriptions() {
        modelSubscriptions.setAll(service.findAllSubscriptionsForUser(user));
        idColumn.setCellValueFactory(new PropertyValueFactory<>("id"));
        daysColumn.setCellValueFactory(new PropertyValueFactory<>("showsLeft"));
        priceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        tableViewSubscriptions.setItems(modelSubscriptions);
    }

    public void onUseSubscriptionClick(ActionEvent actionEvent) throws IOException {
        Subscription subscription = tableViewSubscriptions.getSelectionModel().getSelectedItem();
        subscription.setShowsLeft(subscription.getShowsLeft() - chosenSeats.size());
        if(subscription.getShowsLeft() < 0){
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Error",
                    "You don't have enough shows left in this subscription!");
        }
        else {
            for (Seat seat : chosenSeats.values()) {
                service.makeReservation(user, seat, true);
            }
            if (subscription.getShowsLeft() == 0)
                service.deleteSubscription(subscription);
            else
                service.updateSubscription(subscription);
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success",
                    "The payment was made!");
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("seats-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            ViewSeatsController controller = fxmlLoader.getController();
            controller.settings(service, user, service.findShowOfDay());
            mainPane.getChildren().setAll(dashboard);
        }
    }
}
