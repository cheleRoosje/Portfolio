package org.example;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalcGui {

    //buttons
    private JButton clearBtn;
    private JButton a6Button;
    private JButton a5Button;
    private JButton a4Button;
    private JButton multiplyBtn;
    private JButton a0Button;
    private JButton totalBtn;
    private JButton addBtn;
    private JButton a9Button;
    private JButton a8Button;
    private JButton a7Button;
    private JButton divideBtn;
    private JTextField aNumTextField;
    private JButton a3Button;
    private JButton a2Button;
    private JButton a1Button;
    private JButton subtractBtn;
    private JPanel panelMain;
    private JButton backSpaceBtn;
    private JButton decimalBtn;
    private JFrame mainFrame;

    private Logger logger;

    //creates a new instance of the calculator object called calc
    private Calculator calc = new Calculator();


    //create user interface(GUI)
    public CalcGui(Logger logger) {
        //logger parameter
        this.logger = logger;
        mainFrame = new JFrame("Calculator");
        mainFrame.setSize(400, 400);
        mainFrame.setContentPane(panelMain);
        //required to see calculator
        mainFrame.setVisible(true);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        ActionListener listener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //returns the object that was clicked
                JButton button =(JButton) e.getSource();
                //returns the buttons text
                String text = button.getText();
                //returns the text in the text field and adds the button text acquired in the line above
                aNumTextField.setText(aNumTextField.getText() + text);
            }
        };
        a6Button.addActionListener(listener);
        a5Button.addActionListener(listener);
        a4Button.addActionListener(listener);
        a0Button.addActionListener(listener);
        a9Button.addActionListener(listener);
        a8Button.addActionListener(listener);
        a7Button.addActionListener(listener);
        a3Button.addActionListener(listener);
        a2Button.addActionListener(listener);
        a1Button.addActionListener(listener);
        totalBtn.addActionListener(PerformCalculations);
        divideBtn.addActionListener(OperatorListener);
        multiplyBtn.addActionListener(OperatorListener);
        subtractBtn.addActionListener(OperatorListener);
        addBtn.addActionListener(OperatorListener);
        clearBtn.addActionListener(ClearListener);
        decimalBtn.addActionListener(listener);
        backSpaceBtn.addActionListener(backSpaceListener);
    }

    ActionListener OperatorListener = e -> {
        //returns the object originally clicked
        JButton button = (JButton) e.getSource();
        String text = button.getText();
        aNumTextField.setText(aNumTextField.getText() + text);
        calc.setOperator(text);
    };

    ActionListener ClearListener = e -> {

        //assigns text to a blank string
        String text = "";
        //sets the text field to blank
        aNumTextField.setText(text);
    };

    ActionListener backSpaceListener = e -> {
        //removes the last item in the string by getting length and subtracting one
        aNumTextField.setText(aNumTextField.getText().substring(0, aNumTextField.getText().length()-1));
    };

    ActionListener PerformCalculations = e -> {
        try{
            //puts text from my text field into variable expression
            String expression = aNumTextField.getText();
            //splits the string, puts it in an array, and uses regex to remove or ignore the symbols specified
            String[] parts = expression.split("[\\➕\\➖\\✖➗]");

            if(parts.length != 2){
                //checks to make sure only 2 parts are left
                throw new NumberFormatException("Invalid expression");

            }
            // puts the first part in the num1 variable and the second in num2 and parse them from string to double
            Double num1 = Double.parseDouble(parts[0]);
            Double num2 = Double.parseDouble(parts[1]);

            //sets num1 and num2 in calc
            calc.setNum1(num1);
            calc.setNum2(num2);

            //Extract Operator by replacing the digets 0 to 9 and . with blank space
            String operator = expression.replaceAll("[0-9.]", "");
            //sets the operator in calc
            calc.setOperator(operator);

            //asign result to calc performaneCalculations method
            Double result = calc.performCalculations(logger);
            //sets the value of result to a string and displays it in the text field
            aNumTextField.setText(String.valueOf(result));

            // Log the operation
            String logMessage = String.format("%s %s %s = %s", num1, operator, num2, result);
            logger.log(LogLevel.INFO, logMessage);

            // Display the result in the text field
            aNumTextField.setText(String.valueOf(result));

        //handle the case where input is invalid
        }catch (NumberFormatException ex) {
            aNumTextField.setText("invalid input");
        }
    };


}


