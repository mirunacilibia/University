package repository;

import domain.Seat;
import domain.Show;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import javax.persistence.Query;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class ShowRepositoryHibernate implements ShowRepositoryInterface{

    private SessionFactory sessionFactory;

    public ShowRepositoryHibernate(SessionFactory sessionFactory) {
        this.sessionFactory = sessionFactory;
    }

    @Override
    public Show findOne(Integer integer) {
        try(Session session = sessionFactory.openSession()){
            Transaction tx=null;
            try{
                tx = session.beginTransaction();
                Show show = session.load( Show.class, integer );
                return show;
            } catch(RuntimeException ex){
                System.err.println("Eroare la find " + ex);
                if (tx!=null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Iterable<Show> findAll() {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                List<Show> shows =
                        session.createQuery("from Show ", Show.class).list();
                tx.commit();
                return shows;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la select " + ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    private List<Seat> addInitialSeats(Show entity) {
        List<Seat> seats = new ArrayList<>();
        for(int i = 0; i < entity.getNumberOfSeats(); i++){
            Seat seat = new Seat((int)(i / entity.getRowLength()), (int) (i % entity.getRowLength()),
                    entity.getStartingPrice() + 3 * ((int)(entity.getNumberOfSeats() / entity.getRowLength()) - (int)(i / entity.getRowLength())), false, entity);
            seats.add(seat);
        }
        return seats;
    }

    @Override
    public Show save(Show entity) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                entity.setSeats(addInitialSeats(entity));
                session.persist(entity);
                tx.commit();
                return entity;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la inserare " + ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Integer delete(Integer integer) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();

                Query query = session.createQuery("from Show where id = ?1", Show.class);
                query.setParameter(1, integer);
                Show show = (Show) query.setMaxResults(1).getResultList().get(0);
                session.delete(show);
                tx.commit();
                return integer;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la stergere "+ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Show update(Show entity) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                session.update(entity);
                tx.commit();
                return entity;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la update "+ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Seat updateSeat(Seat seat) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                session.update(seat);
                tx.commit();
                return seat;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la update "+ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Seat findSeat(int row, int column, Show show) {
        try(Session session = sessionFactory.openSession()){
            Transaction tx=null;
            try{
                tx = session.beginTransaction();
                Query query = session.createQuery("from Seat where row = ?1 and column = ?2 and show=?3", Seat.class);
                query.setParameter(1, row);
                query.setParameter(2, column);
                query.setParameter(3, show);
                Seat seat = (Seat) query.setMaxResults(1).getResultList().get(0);
                return seat;
            } catch(RuntimeException ex){
                System.err.println("Eroare la find " + ex);
                if (tx!=null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Show findShowOfDay() {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();

                Query query = session.createQuery("from Show where date = ?1", Show.class);
                String date = LocalDate.now().toString();
                query.setParameter(1, date);
                Show show = (Show) query.setMaxResults(1).getResultList().get(0);
                return show;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la stergere "+ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Seat findOneSeat(Integer integer) {
        try(Session session = sessionFactory.openSession()){
            Transaction tx=null;
            try{
                tx = session.beginTransaction();
                Seat Seat = session.load( Seat.class, integer );
                return Seat;
            } catch(RuntimeException ex){
                System.err.println("Eroare la find " + ex);
                if (tx!=null)
                    tx.rollback();
            }
        }
        return null;
    }
}
