package repository;

import domain.Seat;
import domain.Show;

public interface ShowRepositoryInterface extends Repository<Show> {

    public Seat updateSeat(Seat seat);

    public Seat findSeat(int row, int column, Show show);

    public Seat findOneSeat(Integer integer);

    public Show findShowOfDay();
}
