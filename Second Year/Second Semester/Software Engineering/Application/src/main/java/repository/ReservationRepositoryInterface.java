package repository;

import domain.Reservation;
import domain.User;

public interface ReservationRepositoryInterface extends Repository<Reservation> {

    public Iterable<Reservation> findAllForUser(User user);
}
