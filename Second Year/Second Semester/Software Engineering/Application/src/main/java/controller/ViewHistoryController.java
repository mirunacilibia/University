package controller;

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

public class ViewHistoryController {
    public AnchorPane mainPane;

    public Service service;
    public TableColumn<Seat, Integer> tableColumnRow;
    public TableColumn<Seat, Integer> tableColumnColumn;
    public TableColumn<Seat, Integer> tableColumnPrice;
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
                .filter(x -> !x.getShow().getDate().equals(LocalDate.now().toString()))
                .collect(Collectors.toList()));
        tableColumnRow.setCellValueFactory(new PropertyValueFactory<>("row"));
        tableColumnColumn.setCellValueFactory(new PropertyValueFactory<>("column"));
        tableColumnPrice.setCellValueFactory(new PropertyValueFactory<>("price"));
        tableView.setItems(modelReservations);
    }
}
