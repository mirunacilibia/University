package controller;

import domain.Reservation;
import domain.Seat;
import domain.User;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import javafx.util.Callback;
import service.Service;

import java.io.IOException;
import java.time.LocalDate;
import java.util.stream.Collectors;

public class ViewReservationsController {
    public AnchorPane mainPane;

    public Service service;
    public TableColumn<Seat, Integer> tableColumnRow;
    public TableColumn<Seat, Integer> tableColumnColumn;
    public TableColumn<Seat, Integer> tableColumnPrice;
    public TableColumn<Seat, Void> tableColumnDelete;
    public TableView<Seat> tableView;
    private User user;

    ObservableList<Seat> modelReservations = FXCollections.observableArrayList();

    public void settings(Service service, User user) throws IOException {
        this.service = service;
        this.user = user;
        setTableView();
    }

    public void setTableView() {
        modelReservations.setAll(service.findAllReservationForUser(user)
                .stream().map(x -> {
                    Seat seat = x.getSeat();
                    seat.setId(x.getId());
                    return seat;
                })
                .filter(x -> x.getShow().getDate().equals(LocalDate.now().toString()))
                .collect(Collectors.toList()));
        tableColumnRow.setCellValueFactory(new PropertyValueFactory<>("row"));
        tableColumnColumn.setCellValueFactory(new PropertyValueFactory<>("column"));
        tableColumnPrice.setCellValueFactory(new PropertyValueFactory<>("price"));
        addDeleteButtonToTable();
        tableView.setItems(modelReservations);
    }

    private void addDeleteButtonToTable() {
        Callback<TableColumn<Seat, Void>, TableCell<Seat, Void>> cellFactory
                = new Callback<TableColumn<Seat, Void>, TableCell<Seat, Void>>() {
            @Override
            public TableCell<Seat, Void> call(final TableColumn<Seat, Void> param) {
                final TableCell<Seat, Void> cell = new TableCell<Seat, Void>() {

                    private final Button btn = new Button("Delete");
                    @Override
                    public void updateItem(Void item, boolean empty) {
                        super.updateItem(item, empty);
                        btn.getStyleClass().add("buttonMain");
                        if (empty) {
                            setGraphic(null);
                            setText(null);
                        } else {
                            btn.setOnAction((ActionEvent event) -> {
                                Seat reservation = getTableView().getItems().get(getIndex());
                                service.deleteReservation(reservation.getId());
                                MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Delete", "Reservation deleted!");
                                setTableView();
                            });
                            setGraphic(btn);
                            setText(null);
                        }
                    }
                };
                return cell;
            }
        };
        tableColumnDelete.setCellFactory(cellFactory);
    }
}
