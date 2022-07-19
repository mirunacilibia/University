package controller;

import domain.User;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import service.Service;

import java.io.IOException;
import java.util.Map;

public class MainController {
    public AnchorPane mainPane;

    public Service service;
    private User user;

    public void settings(Service service, User user) throws IOException {
        this.service = service;
        this.user = user;
        setViewSeats();
    }

    private void setViewSeats() throws IOException {
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

    public void logOut(ActionEvent actionEvent) {
        Stage stage = (Stage) mainPane.getScene().getWindow();
        stage.close();
    }

    public void onViewSeatsClick(ActionEvent actionEvent) throws IOException {
        setViewSeats();
    }

    public void onAddShowClick(ActionEvent actionEvent) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("new-show-view.fxml"));
        AnchorPane dashboard = fxmlLoader.load();
        Node oldRegion = mainPane.getChildren().set(0, dashboard);
        Map<Object, Object> properties = dashboard.getProperties();
        oldRegion.getProperties().forEach(properties::putIfAbsent);
        NewShowController controller = fxmlLoader.getController();
        controller.settings(service, user);
        mainPane.getChildren().setAll(dashboard);
    }

    public void onUpdateShowClick(ActionEvent actionEvent) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("update-show-view.fxml"));
        AnchorPane dashboard = fxmlLoader.load();
        Node oldRegion = mainPane.getChildren().set(0, dashboard);
        Map<Object, Object> properties = dashboard.getProperties();
        oldRegion.getProperties().forEach(properties::putIfAbsent);
        UpdateShowController controller = fxmlLoader.getController();
        controller.settings(service, user);
        mainPane.getChildren().setAll(dashboard);
    }

    public void onReserveSeatClick(ActionEvent actionEvent) {
    }

    public void onViewReservationsClick(ActionEvent actionEvent) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("reservations-view.fxml"));
        AnchorPane dashboard = fxmlLoader.load();
        Node oldRegion = mainPane.getChildren().set(0, dashboard);
        Map<Object, Object> properties = dashboard.getProperties();
        oldRegion.getProperties().forEach(properties::putIfAbsent);
        ViewReservationsController controller = fxmlLoader.getController();
        controller.settings(service, user);
        mainPane.getChildren().setAll(dashboard);
    }

    public void onHistoryClick(ActionEvent actionEvent) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("history-view.fxml"));
        AnchorPane dashboard = fxmlLoader.load();
        Node oldRegion = mainPane.getChildren().set(0, dashboard);
        Map<Object, Object> properties = dashboard.getProperties();
        oldRegion.getProperties().forEach(properties::putIfAbsent);
        ViewHistoryController controller = fxmlLoader.getController();
        controller.settings(service, user);
        mainPane.getChildren().setAll(dashboard);
    }

    public void onSubscriptionClick(ActionEvent actionEvent) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("subscription-view.fxml"));
        AnchorPane dashboard = fxmlLoader.load();
        Node oldRegion = mainPane.getChildren().set(0, dashboard);
        Map<Object, Object> properties = dashboard.getProperties();
        oldRegion.getProperties().forEach(properties::putIfAbsent);
        ViewSubscriptionsController controller = fxmlLoader.getController();
        controller.settings(service, user);
        mainPane.getChildren().setAll(dashboard);
    }
}
