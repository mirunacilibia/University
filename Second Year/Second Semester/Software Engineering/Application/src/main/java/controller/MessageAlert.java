package controller;

import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class MessageAlert { /**
 * Function create a new window with given  information
 * @param owner null always
 * @param type Information/Alert
 * @param header Title
 * @param text Text from window
 */
static void showMessage(Stage owner, Alert.AlertType type, String header, String text){
    Alert message=new Alert(type);
    message.setHeaderText(header);
    Stage stage = (Stage) message.getDialogPane().getScene().getWindow();
    message.setContentText(text);
    Image icon =   new Image("icons/preview.png");
    stage.getIcons().add(icon);
    message.initOwner(owner);
    message.setTitle("Information");
    message.showAndWait();
}
    /**
     * Function shows the error message
     * @param owner null always
     * @param text Text from window
     */
    static void showErrorMessage(Stage owner, String text){
        Alert message=new Alert(Alert.AlertType.ERROR);
        Stage stage = (Stage) message.getDialogPane().getScene().getWindow();
        Image icon =   new Image("icons/preview.png");
        stage.getIcons().add(icon);
        message.initOwner(owner);
        message.setTitle("Error message");
        message.setContentText(text);
        message.showAndWait();
    }

}
