package domain;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Show implements Serializable {

    private String name;
    private int numberOfSeats;
    private String date;
    private double startingPrice;
    private List<Seat> seats = new ArrayList<>();
    private int id;

    private int rowLength = 7;

    public Show(String name, int numberOfSeats, String date, double startingPrice) {
        this.name = name;
        this.numberOfSeats = numberOfSeats;
        this.date = date;
        this.startingPrice = startingPrice;
    }

    public Show() {
    }

    public int getRowLength() {
        return rowLength;
    }

    public void setRowLength(int rowLength) {
        this.rowLength = rowLength;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getStartingPrice() {
        return startingPrice;
    }

    public void setStartingPrice(double startingPrice) {
        this.startingPrice = startingPrice;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getNumberOfSeats() {
        return numberOfSeats;
    }

    public void setNumberOfSeats(int numberOfSeats) {
        this.numberOfSeats = numberOfSeats;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public List<Seat> getSeats() {
        return seats;
    }

    public void setSeats(List<Seat> seats) {
        this.seats = seats;
    }

    @Override
    public String toString() {
        return date + " - " + name;
    }
}
