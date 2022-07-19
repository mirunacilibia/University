package start;

import controller.LoginController;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import repository.*;
import service.Service;

public class Start extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        final StandardServiceRegistry registry = new StandardServiceRegistryBuilder()
                .configure() // configures settings from hibernate.cfg.xml
                .build();
        SessionFactory sessionFactory = null;
        try {
            sessionFactory = new MetadataSources(registry).buildMetadata().buildSessionFactory();
        } catch (Exception e) {
            System.err.println("Exception " + e);
            StandardServiceRegistryBuilder.destroy(registry);
        }

        Service service = new Service(
                new UserRepositoryHibernate(sessionFactory),
                new ShowRepositoryHibernate(sessionFactory),
                new ReservationRepositoryHibernate(sessionFactory),
                new SubscriptionRepositoryHibernate(sessionFactory));

        FXMLLoader loader=new FXMLLoader();
        loader.setLocation(getClass().getResource("login-view.fxml"));
        Parent root = loader.load();
        LoginController controller = loader.getController();
        controller.settings(service);

        Scene scene = new Scene(root);
        primaryStage.setTitle("Seat Reservations");
        primaryStage.setScene(scene);
        primaryStage.show();

        SessionFactory finalSessionFactory = sessionFactory;
        primaryStage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent event) {
                if (finalSessionFactory != null) {
                    finalSessionFactory.close();
                }
                System.exit(0);
            }
        });

//        if (sessionFactory != null) {
//            sessionFactory.close();
//        }
    }
}
