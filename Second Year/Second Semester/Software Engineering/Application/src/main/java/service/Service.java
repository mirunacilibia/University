package service;

import domain.*;
import repository.*;

import java.util.List;
import java.util.Objects;

public class Service {

    private UserRepositoryInterface userRepository;
    private ShowRepositoryInterface showRepository;
    private ReservationRepositoryHibernate reservationRepository;
    private SubscriptionRepositoryInterface subscriptionRepository;

    public Service(UserRepositoryInterface userRepository, ShowRepositoryInterface showRepository, ReservationRepositoryHibernate reservationRepository, SubscriptionRepositoryInterface subscriptionRepository) {
        this.userRepository = userRepository;
        this.showRepository = showRepository;
        this.reservationRepository = reservationRepository;
        this.subscriptionRepository = subscriptionRepository;
    }

    public User login(String email, String password) throws Exception {
        User user = userRepository.findByEmail(email);
        if(user == null)
            throw new Exception("There is no user with this email!");
        if(!Objects.equals(user.getPassword(), password))
            throw new Exception("Password incorrect!");
        return user;
    }

    public void saveShow(String name, int numberOfSeats, String date, double startingPrice){
        showRepository.save(new Show(name, numberOfSeats, date, startingPrice));
    }

    public void updateShow(int id, String name, String date){
        Show show = showRepository.findOne(id);
        show.setDate(date);
        show.setName(name);
        showRepository.update(show);
    }

    public List<Show> findAllShows(){
        return (List<Show>) showRepository.findAll();
    }

    public Show findShowOfDay(){
        return showRepository.findShowOfDay();
    }

    public List<Reservation> findAllReservationForUser(User user){
        return (List<Reservation>) reservationRepository.findAllForUser(user);
    }

    public Seat findSeat(int row, int column, Show show){
        return showRepository.findSeat(row, column, show);
    }

    public void makeReservation(User user, Seat seat, Boolean paid){
        reservationRepository.save(new Reservation(user, seat, paid));
        seat.setOccupied(true);
        showRepository.updateSeat(seat);
    }

    public void deleteReservation(Integer id){
        Seat seat = reservationRepository.findOne(id).getSeat();
        seat.setOccupied(false);
        showRepository.updateSeat(seat);
        reservationRepository.delete(id);
    }

    public void saveSubscription(Subscription subscription){
        subscriptionRepository.save(subscription);
    }

    public void deleteSubscription(Subscription subscription){
        subscriptionRepository.delete(subscription.getId());
    }

    public List<Subscription> findAllSubscriptionsForUser(User user){
        return (List<Subscription>) subscriptionRepository.findAllForUser(user);
    }

    public void updateSubscription(Subscription subscription){
        subscriptionRepository.update(subscription);
    }
}
