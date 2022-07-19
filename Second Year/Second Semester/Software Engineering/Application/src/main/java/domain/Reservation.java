package domain;

import java.io.Serializable;

public class Reservation implements Serializable {

        private Seat seat;
        private User user;
        private int id;
        private Boolean paid;

    public Reservation(User user, Seat seat, Boolean isPaid) {
        this.seat = seat;
        this.user = user;
        this.paid = isPaid;
    }

    public Reservation() {
    }

    public Boolean getPaid() {
        return paid;
    }

    public void setPaid(Boolean paid) {
        this.paid = paid;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Seat getSeat() {
        return seat;
    }

    public void setSeat(Seat seat) {
        this.seat = seat;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    @Override
    public String toString() {
        return "Reservation{" +
                "seat=" + seat +
                ", user=" + user +
                ", id=" + id +
                ", paid=" + paid +
                '}';
    }
}
