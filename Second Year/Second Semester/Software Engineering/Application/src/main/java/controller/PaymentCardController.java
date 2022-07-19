package controller;

import domain.Seat;
import domain.Show;
import domain.Subscription;
import domain.User;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import service.Service;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class PaymentCardController {
    public TextField textFieldName;
    public Label labelPrice;
    public TextField textFieldNumber;
    public TextField textFieldDate;
    public TextField textFieldCVV;
    public AnchorPane mainPane;

    private Service service;
    private User user;
    private Show show;
    private HashMap<Integer, Seat> chosenSeats;
    private double price = 0;
    private Subscription subscription;

    public void settings(Service service, User user, Show show, HashMap<Integer, Seat> chosenSeats, Subscription subscription) {
        this.service = service;
        this.user = user;
        this.show = show;
        this.chosenSeats = chosenSeats;
        this.subscription = subscription;
        setPrice();
    }

    private void setPrice() {
        if(subscription == null) {
            for (Seat seat : chosenSeats.values()) {
                price += seat.getPrice();
            }
            labelPrice.setText("Price to pay: " + price + " RON");
        } else
            labelPrice.setText("Price to pay: " + subscription.getPrice() + " RON");
    }

    public void onPayClick(ActionEvent actionEvent) throws IOException {
        if(subscription == null) {
            for (Seat seat : chosenSeats.values()) {
                service.makeReservation(user, seat, true);
            }
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success",
                    "The payment was made!");
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("seats-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            ViewSeatsController controller = fxmlLoader.getController();
            // aici vom modifica
            controller.settings(service, user, service.findShowOfDay());
            mainPane.getChildren().setAll(dashboard);
        } else {
            subscription.setPaid(true);
            service.saveSubscription(subscription);
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success",
                    "The payment was made!");
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("seats-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            ViewSeatsController controller = fxmlLoader.getController();
            // aici vom modifica
            controller.settings(service, user, service.findShowOfDay());
            mainPane.getChildren().setAll(dashboard);
        }
    }
}
