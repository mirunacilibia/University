package repository;

import domain.Subscription;
import domain.User;

public interface SubscriptionRepositoryInterface extends Repository<Subscription> {

    public Iterable<Subscription> findAllForUser(User user);
}
