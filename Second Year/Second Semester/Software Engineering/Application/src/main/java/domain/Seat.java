package domain;

public class Seat {

    private int row;
    private int column;
    private int number;
    private double price;
    private boolean occupied;
    private int id;
    private Show show;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Seat(int row, int column, double price, boolean occupied, Show show) {
        this.row = row;
        this.column = column;
        this.price = price;
        this.occupied = occupied;
        this.show = show;
    }

    public Seat() {
    }

    public Show getShow() {
        return show;
    }

    public void setShow(Show show) {
        this.show = show;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getColumn() {
        return column;
    }

    public void setColumn(int column) {
        this.column = column;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public boolean isOccupied() {
        return occupied;
    }

    public void setOccupied(boolean occupied) {
        this.occupied = occupied;
    }

    @Override
    public String toString() {
        return "Seat{" +
                "row=" + row +
                ", column=" + column +
                ", number=" + number +
                ", price=" + price +
                ", occupied=" + occupied +
                ", id=" + id +
                '}';
    }
}
