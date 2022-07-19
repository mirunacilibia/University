package controller;

import domain.Seat;
import domain.Show;
import domain.User;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.layout.*;
import service.Service;

import java.io.IOException;
import java.util.*;

public class ViewSeatsController {
    public AnchorPane mainPane;
    public GridPane gridPane;
    public ComboBox comboBoxPayment;
    public Label labelError;

    private Service service;
    private User user;
    private Show show;

    private HashMap<Integer, Seat> chosenSeats = new HashMap<>();

    public void settings(Service service, User user, Show show) {
        this.service = service;
        this.user = user;
        this.show = show;
        if(show == null){
            labelError.setText("There is no show today!");
            return;
        } else {
            labelError.setText(show.getName());
            initializeSeats();
            ObservableList<String> paymentObservableList = FXCollections.observableArrayList();
            paymentObservableList.add("Cash");
            paymentObservableList.add("Card");
            paymentObservableList.add("Subscription");
            comboBoxPayment.setItems(paymentObservableList);
        }
    }

    private void initializeSeats() {
        int noSeats = show.getNumberOfSeats();
        for(int i = 0; i < noSeats; i++){
            Button seatButton = new Button();
            Seat seat = service.findSeat(i / gridPane.getRowCount(), i % gridPane.getRowCount(), show);
            if(seat.isOccupied())
                seatButton.getStyleClass().add("seatOccupied");
            else
                seatButton.getStyleClass().add("seatUnoccupied");
            seatButton.setOnAction(e -> {
                if(seatButton.getStyleClass().contains("seatUnoccupied")) {
                    seatButton.getStyleClass().clear();
                    seatButton.getStyleClass().add("seatPicked");
                    chosenSeats.put(seat.getId(), seat);
                } else if(seatButton.getStyleClass().contains("seatPicked")){
                    seatButton.getStyleClass().clear();
                    seatButton.getStyleClass().add("seatUnoccupied");
                    chosenSeats.remove(seat.getId());
                }
                System.out.println(chosenSeats);
            });
            gridPane.add(seatButton, i % gridPane.getRowCount(), i / gridPane.getRowCount());
        }
    }

    public void reserveSeat(ActionEvent actionEvent) throws IOException {
        String paymentMethod = (String) comboBoxPayment.getValue();
        if(paymentMethod.equals("Card")){
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("payment-card-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            PaymentCardController controller = fxmlLoader.getController();
            controller.settings(service, user, show, chosenSeats, null);
            mainPane.getChildren().setAll(dashboard);
        } else if(paymentMethod.equals("Subscription")){
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("payment-subscription-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            PaymentSubscriptionController controller = fxmlLoader.getController();
            controller.settings(service, user, show, chosenSeats);
            mainPane.getChildren().setAll(dashboard);
        }
        else {
            double price = 0;
            for(Seat seat: chosenSeats.values()){
                service.makeReservation(user, seat, false);
                price += seat.getPrice();
            }
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success",
                    "You have reserved the seats!" +
                        "\nCome to the theatre at least an hour before the show to pay your tickets." +
                        "\nPrice to pay:" + price + " RON");
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
