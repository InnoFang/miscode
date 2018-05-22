package io.innofang.lexer.view;

import io.innofang.lexer.MainApp;
import io.innofang.lexer.model.Token;
import io.innofang.lexer.model.TokenItem;
import io.innofang.lexer.model.TokenType;
import io.innofang.lexer.utils.Lexer;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.stage.FileChooser;

import java.io.File;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 20:23
 */
public class RootLayoutController {

    private MainApp mainApp;

    public void setMainApp(MainApp mainApp) {
        this.mainApp = mainApp;
    }

    @FXML
    private void handleNew() {
        mainApp.getTokenData().clear();
        mainApp.setCode("");
        mainApp.setCodeFilePath(null);
    }

    @FXML
    private void handleOpen() {
        FileChooser fileChooser = new FileChooser();

        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter(
                "XML files (*.pas)", "*.pas");
        fileChooser.getExtensionFilters().add(extFilter);

        File file = fileChooser.showOpenDialog(mainApp.getPrimaryStage());

        if (null != file) {
            mainApp.loadCodeFromFile(file);
        }
    }

    @FXML
    private void handleSave() {
        File codeFile = mainApp.getCodeFilePath();
        if (null != codeFile) {
            mainApp.saveCodeToFile(codeFile);
        } else {
            handleSaveAs();
        }
    }

    @FXML
    private void handleSaveAs() {
        FileChooser fileChooser = new FileChooser();

        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter(
                "XML files (*.pas)", "*.pas");
        fileChooser.getExtensionFilters().add(extFilter);

        File file = fileChooser.showSaveDialog(mainApp.getPrimaryStage());

        if (null != file) {
            // Make sure it has the correct extension
            if (!file.getPath().endsWith(".pas")) {
                file = new File(file.getPath() + ".pas");
            }
            mainApp.saveCodeToFile(file);
        }
    }

    @FXML
    private void handleExit(){
        System.exit(0);
    }

    @FXML
    private void handleAbout() {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Lexer");
        alert.setHeaderText("About");
        alert.setContentText("Author: Inno Fang\nWebsite: https://github.com/innofnag");
        alert.show();
    }

    @FXML
    public void handleRun() {
        mainApp.getTokenData().clear();
        Lexer lexer = new Lexer(mainApp.getCode());
        Token token;
        while ((token = lexer.getNextToken()).getType() != TokenType.EOF) {
            mainApp.getTokenData().add(new TokenItem(token));
        }
    }
}

