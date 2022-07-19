package domain;

import java.io.Serializable;

public class User implements Serializable {

    private String name;
    private String email;
    private String password;
    private boolean admin;

    public User() {
        
    }

    public boolean getAdmin() {
        return admin;
    }

    public void setAdmin(boolean admin) {
        this.admin = admin;
    }

    private int id;

    /**
     * Constructor for the User
     * @param name - string - the User's name
     * @param email - string - the User's phone number
     * @param password - string - the User's password
     */
    public User(String name, String email, String password, boolean admin) {
        this.name = name;
        this.email = email;
        this.password = password;
        this.admin = admin;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    /**
     * Getter
     * @return - string, email of the User
     */
    public String getEmail() {
        return email;
    }

    /**
     * Getter
     * @return - string, encrypted password of the User
     */
    public String getPassword() {
        return password;
    }

    /**
     * Setter
     * @param email - string
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /**
     * Setter - sets a new password
     * @param password - string
     */
    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "User{" +
                "id='" + getId() + '\'' +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", password='" + password + '\'' +
                '}';
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
