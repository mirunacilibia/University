package repository;

import java.io.Serializable;

public interface Repository<E extends Serializable> {

    /**
     * @param Integer -the id of the entity to be returned
     *           Integer must not be null
     * @return the entity with the specified Integer
     *          or null - if there is no entity with the given Integer
     * @throws IllegalArgumentException
     *                  if Integer is null.
     */
    E findOne(Integer Integer);

    /**
     * @return all entities
     */
    Iterable<E> findAll();

    /**
     * @param entity
     *         entity must be not null
     * @return the entity - if the given entity is saved
     *         otherwise returns null (Integer already exists)
     * @throws IllegalArgumentException
     *             if the given entity is null.     *
     */
    E save(E entity);


    /**
     *  removes the entity with the specified id
     * @param Integer
     *      Integer must be not null
     * @return the removed entity Integer or null if there is no entity with the given Integer
     * @throws IllegalArgumentException
     *                   if the given Integer is null.
     */
    Integer delete(Integer Integer);

    /**
     * @param entity
     *          entity must not be null
     * @return the entity - if the given entity is saved
     *         otherwise returns null (Integer already exists)
     * @throws IllegalArgumentException
     *             if the given entity is null.
     */
    E update(E entity);
}