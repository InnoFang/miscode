package io.innofang.lexer.view;

import io.innofang.lexer.MainApp;
import io.innofang.lexer.model.TokenItem;
import javafx.fxml.FXML;
import javafx.scene.control.*;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 20:00
 */
public class LexerOverviewController {

    @FXML
    private TableView<TokenItem> lexerTable;
    @FXML
    private TableColumn<TokenItem, String> valueColumn;
    @FXML
    private TableColumn<TokenItem, String> typeColumn;
    @FXML
    private TextArea codePane;

    private MainApp mainApp;


    public LexerOverviewController() {
    }


    @FXML
    private void initialize() {
        valueColumn.setCellValueFactory(cellData -> cellData.getValue().valueProperty());
        typeColumn.setCellValueFactory(cellData -> cellData.getValue().typeProperty());
    }

    public void setMainApp(MainApp mainApp) {
        this.mainApp = mainApp;

        lexerTable.setItems(mainApp.getTokenData());
    }

    public void setCode(String code) {
        codePane.setText(code);
    }

    public String getCode() {
        return codePane.getText();
    }

}
