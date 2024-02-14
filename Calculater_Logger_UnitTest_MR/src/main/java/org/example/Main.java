package org.example;


public class Main {
    public static void main(String[] args) {
        //create a Logger instance
        Logger logger = Logger.getInstance();

        //required to see calculator - create a CalcGui instance and pass the Logger instance
        CalcGui CalcGui = new CalcGui(logger);

        // The Logger instance is shared among different components, providing a centralized logging system.
        // The CalcGui instance is initialized with the Logger, enabling logging functionality in the calculator GUI.

//        Calculator calc = new Calculator();
//        calc.setNum1(1.0);
//        calc.setNum2(5.0);
//        calc.setOperator("➕");
//
//        Double testResult = calc.performCalculations();
//        System.out.println(testResult);



        System.out.println("Calculator");

        // Display logs
        logger.displayLogs();

        }

}