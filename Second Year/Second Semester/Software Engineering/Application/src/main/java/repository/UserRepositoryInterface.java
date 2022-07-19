package repository;

import domain.User;

public interface UserRepositoryInterface extends Repository<User>{

    public User findByEmail(String email);
}
