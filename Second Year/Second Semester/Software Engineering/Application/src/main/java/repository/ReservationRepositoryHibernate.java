package repository;

import domain.Seat;
import domain.Reservation;
import domain.User;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import javax.persistence.Query;
import java.util.ArrayList;
import java.util.List;

public class ReservationRepositoryHibernate implements ReservationRepositoryInterface{

    private SessionFactory sessionFactory;

    public ReservationRepositoryHibernate(SessionFactory sessionFactory) {
        this.sessionFactory = sessionFactory;
    }

    @Override
    public Reservation findOne(Integer integer) {
        try(Session session = sessionFactory.openSession()){
            Transaction tx=null;
            try{
                tx = session.beginTransaction();
                return session.load( Reservation.class, integer );
            } catch(RuntimeException ex){
                System.err.println("Eroare la find " + ex);
                if (tx!=null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Iterable<Reservation> findAll() {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                List<Reservation> Reservations =
                        session.createQuery("from Reservation ", Reservation.class).list();
                tx.commit();
                return Reservations;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la select " + ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }

    @Override
    public Reservation save(Reservation entity) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                System.out.println(entity);
                tx = session.beginTransaction();
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

                Query query = session.createQuery("from Reservation where id = ?1", Reservation.class);
                query.setParameter(1, integer);
                Reservation Reservation = (Reservation) query.setMaxResults(1).getResultList().get(0);
                session.delete(Reservation);
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
    public Reservation update(Reservation entity) {
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
    public Iterable<Reservation> findAllForUser(User user) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                Query query = session.createQuery("from Reservation where user = ?1", Reservation.class);
                query.setParameter(1, user);
                List<Reservation> Reservations = (List<Reservation>) query.getResultList();
                tx.commit();
                return Reservations;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la select " + ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }
}
