package controller;

import domain.User;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import service.Service;

import java.io.IOException;
import java.util.Map;

public class NewShowController {
    public AnchorPane mainPane;
    public TextField textFieldName;
    public Spinner<Integer> spinnerNoSeats;
    public Spinner<Integer> spinnerStartingPrice;
    public DatePicker datePicker;

    public Service service;
    private User user;

    public void settings(Service service, User user) {
        this.service = service;
        this.user = user;
        spinnerNoSeats.setValueFactory( new SpinnerValueFactory.IntegerSpinnerValueFactory(1, 28, 14));
        spinnerStartingPrice.setValueFactory( new SpinnerValueFactory.IntegerSpinnerValueFactory(10, 50, 20));
    }

    public void onSaveShowClick(ActionEvent actionEvent) {
        String name = textFieldName.getText();
        int numberOfSeats = spinnerNoSeats.getValue();
        int startingPrice = spinnerStartingPrice.getValue();
        String date = datePicker.getValue().toString();

        try {
            service.saveShow(name, numberOfSeats, date, startingPrice);
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Success", "The show was saved");

            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("seats-view.fxml"));
            AnchorPane dashboard = fxmlLoader.load();
            Node oldRegion = mainPane.getChildren().set(0, dashboard);
            Map<Object, Object> properties = dashboard.getProperties();
            oldRegion.getProperties().forEach(properties::putIfAbsent);
            ViewSeatsController controller = fxmlLoader.getController();
            controller.settings(service, user, service.findShowOfDay());
            mainPane.getChildren().setAll(dashboard);
        } catch (Exception e) {
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Error", "The show could not be saved!");

            textFieldName.clear();
        }
    }
}
