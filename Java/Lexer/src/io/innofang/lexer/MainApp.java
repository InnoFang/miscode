package io.innofang.lexer;

import io.innofang.lexer.model.Token;
import io.innofang.lexer.model.TokenItem;
import io.innofang.lexer.model.TokenType;
import io.innofang.lexer.utils.CloseUtil;
import io.innofang.lexer.utils.InputReader;
import io.innofang.lexer.utils.Lexer;
import io.innofang.lexer.view.LexerOverviewController;
import io.innofang.lexer.view.RootLayoutController;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

import java.io.*;
import java.util.prefs.Preferences;

public class MainApp extends Application {

    private Stage primaryStage;
    private BorderPane rootLayout;
    private LexerOverviewController lexerOverviewController;

    private ObservableList<TokenItem> tokenData = FXCollections.observableArrayList();

    public static void main(String[] args) {
        launch(args);
    }

    public MainApp() {
    }

    public ObservableList<TokenItem> getTokenData() {
        return tokenData;
    }

    public Stage getPrimaryStage() {
        return primaryStage;
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        this.primaryStage = primaryStage;
        this.primaryStage.setTitle("AddressApp");

        // Set the application icon.
        //this.primaryStage.getIcons().add(new Image("file:resources/images/address_book_32.png"));

        initRootLayout();

        showLexerOverview();
    }

    private void initRootLayout() {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/RootLayout.fxml"));
            rootLayout = loader.load();

            Scene scene = new Scene(rootLayout);
            primaryStage.setScene(scene);

            RootLayoutController controller = loader.getController();
            controller.setMainApp(this);

            primaryStage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private void showLexerOverview() {
        try {
            // Load person overview.
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/LexerOverview.fxml"));
            AnchorPane personOverView = loader.load();

            rootLayout.setCenter(personOverView);

            lexerOverviewController = loader.getController();
            lexerOverviewController.setMainApp(this);

            File file = getCodeFilePath();
            if (null != file) {
                loadCodeFromFile(file);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setCode(String code) {
        lexerOverviewController.setCode(code);
    }

    public String getCode() {
        return lexerOverviewController.getCode();
    }


    public File getCodeFilePath() {
        Preferences prefs = Preferences.userNodeForPackage(MainApp.class);
        String filePath = prefs.get("filePath", null);
        if (null != filePath) {
            return new File(filePath);
        } else {
            return null;
        }
    }


    public void setCodeFilePath(File file) {
        Preferences prefs = Preferences.userNodeForPackage(MainApp.class);
        if (null != file) {
            prefs.put("filePath", file.getPath());

            primaryStage.setTitle("Lexer - " + file.getName());
        } else {
            prefs.remove("filePath");

            primaryStage.setTitle("Lexer");
        }
    }

    public void loadCodeFromFile(File file) {
        try {

            if (file.exists()) System.setIn(new FileInputStream(file));
            InputReader in = new InputReader(System.in);
            StringBuilder code = new StringBuilder();
            String line;
            while ((line = in.nextLine()) != null) {
                code.append(line).append("\n");
            }
            setCode(code.toString());

            tokenData.clear();
            Lexer lexer = new Lexer(code.toString());
            Token token;
            while ((token = lexer.getNextToken()).getType() != TokenType.EOF) {
                tokenData.add(new TokenItem(token));
            }

            setCodeFilePath(file);
        } catch (Exception e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("Could not load data from file:\n" + file.getPath());
            alert.setContentText(e.toString());
            alert.show();
        }
    }

    public void saveCodeToFile(File file) {
        FileOutputStream fs = null;
        BufferedOutputStream bos = null;
        try {
            fs = new FileOutputStream(file);
            bos = new BufferedOutputStream(fs);
            bos.write(getCode().getBytes());
            bos.flush();

            setCodeFilePath(file);
        } catch (Exception e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("Could not save data to file:\n" + file.getPath());
            alert.setContentText(e.toString());
            alert.show();
        } finally {
            CloseUtil.close(fs);
            CloseUtil.close(bos);
        }
    }
}
