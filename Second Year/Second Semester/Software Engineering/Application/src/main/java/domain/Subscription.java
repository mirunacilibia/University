package domain;

import java.io.Serializable;

public class Subscription implements Serializable {

    private int id;
    private User user;
    private int price;
    private int showsLeft;
    private Boolean paid;

    public Subscription(User user, int price, int showsLeft, Boolean paid) {
        this.user = user;
        this.price = price;
        this.showsLeft = showsLeft;
        this.paid = paid;
    }

    public Subscription() {

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getShowsLeft() {
        return showsLeft;
    }

    public void setShowsLeft(int showsLeft) {
        this.showsLeft = showsLeft;
    }

    public Boolean getPaid() {
        return paid;
    }

    public void setPaid(Boolean paid){
        this.paid = paid;
    }

    @Override
    public String toString() {
        return "Subscription{" +
                "id=" + id +
                ", user=" + user +
                ", price=" + price +
                ", showsLeft=" + showsLeft +
                ", paid=" + paid +
                '}';
    }
}
