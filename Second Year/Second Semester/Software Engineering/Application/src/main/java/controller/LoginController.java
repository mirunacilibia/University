package controller;

import domain.User;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import service.Service;

import java.io.IOException;

public class LoginController {
    public Button loginButton;
    public PasswordField textFieldPassword;
    public TextField textFieldEmail;
    public AnchorPane mainPane;

    public Service service;

    public void settings(Service service){
        this.service = service;
    }

    public void onLoginClick(ActionEvent actionEvent) {
        String email = textFieldEmail.getText();
        String password = textFieldPassword.getText();
        try {
            User user = service.login(email, password);

            Stage stage = (Stage) loginButton.getScene().getWindow();
            stage.close();

            FXMLLoader loader=new FXMLLoader();
            if(user.getAdmin())
                loader.setLocation(getClass().getResource("main-view-admin.fxml"));
            else
                loader.setLocation(getClass().getResource("main-view.fxml"));
            Parent root = loader.load();
            MainController controller = loader.getController();
            controller.settings(service, user);

            Scene scene = new Scene(root);
            Stage stage2 = new Stage();
            stage2.setTitle("Seat Reservation Application");
            stage2.setScene(scene);
            stage2.show();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Error", e.getMessage());
        }
    }
}
