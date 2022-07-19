package repository;

import domain.Show;
import domain.Subscription;
import domain.User;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import javax.persistence.Query;
import java.util.List;

public class SubscriptionRepositoryHibernate implements SubscriptionRepositoryInterface{

    public SubscriptionRepositoryHibernate(SessionFactory sessionFactory) {
        this.sessionFactory = sessionFactory;
    }

    private SessionFactory sessionFactory;

    @Override
    public Subscription findOne(Integer Integer) {
        return null;
    }

    @Override
    public Iterable<Subscription> findAll() {
        return null;
    }

    @Override
    public Subscription save(Subscription entity) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                session.save(entity);
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

                Query query = session.createQuery("from Subscription where id = ?1", Subscription.class);
                query.setParameter(1, integer);
                Subscription show = (Subscription) query.setMaxResults(1).getResultList().get(0);
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
    public Subscription update(Subscription entity) {
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
    public Iterable<Subscription> findAllForUser(User user) {
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                Query query = session.createQuery("from Subscription where user = ?1", Subscription.class);
                query.setParameter(1, user);
                List<Subscription> Subscription = (List<Subscription>) query.getResultList();
                tx.commit();
                return Subscription;
            } catch (RuntimeException ex) {
                System.err.println("Eroare la select " + ex);
                if (tx != null)
                    tx.rollback();
            }
        }
        return null;
    }
}
