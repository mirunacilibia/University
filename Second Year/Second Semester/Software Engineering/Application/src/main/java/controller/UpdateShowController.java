package controller;

import domain.Show;
import domain.User;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import service.Service;

import java.util.List;
import java.util.Map;

public class UpdateShowController {
    public TextField textFieldName;
    public DatePicker datePicker;

    public Service service;
    public ComboBox<Show> comboBoxShows;
    public AnchorPane mainPane;
    private User user;

    public void settings(Service service, User user) {
        this.service = service;
        this.user = user;
        setComboBox();
    }

    private void setComboBox() {
        List<Show> shows = service.findAllShows();
        ObservableList<Show> showObservableList = FXCollections.observableArrayList();
        showObservableList.setAll(shows);
        comboBoxShows.setItems(showObservableList);
    }

    public void onUpdateShowClick(ActionEvent actionEvent) {
        String name = textFieldName.getText();
        String date = datePicker.getValue().toString();
        int id = comboBoxShows.getValue().getId();

        try {
            service.updateShow(id, name, date);
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
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Error", "The show could not be saved!\n" + e.getMessage());
            textFieldName.clear();
        }
    }
}
