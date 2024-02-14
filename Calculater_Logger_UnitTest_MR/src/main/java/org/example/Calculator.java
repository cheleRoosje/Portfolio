package org.example;


import java.text.DecimalFormat;

public class Calculator {
    Double num1;
    Double num2;
    String operator;

    public void setOperator(String operator){
        this.operator = operator;
    }

    public void setNum1(Double num1){
        this.num1 = num1;
    }
    public void setNum2(Double num2){
        this.num2 = num2;
    }

    public Double performCalculations(Logger logger){
        //returns the calculation result that matches the operator clicked
        Double result = 0.0;
        if("➕".equals(operator)){
            result = num1 + num2;
        } else if ("➖".equals(operator)) {
            result = num1 - num2;
        } else if ("✖".equals(operator)) {
            result = num1 * num2;
        } else if ("➗".equals(operator)) {
            if(num2 != 0) {
                result = num1 / num2;
            }else {
                //Handle division by zero error here will return 0
                result = 0.0;
                logger.log(LogLevel.ERROR, "Division by zero error.");
            }
        }
        // Round the result to two decimal places
        result = roundToTwoDecimalPlaces(result);

        return result;
    }
    private Double roundToTwoDecimalPlaces(Double value) {
        // Using Math.round()
        // double roundedValue = Math.round(value * 100.0) / 100.0;

        // Using DecimalFormat
        DecimalFormat decimalFormat = new DecimalFormat("#.##");
        return Double.parseDouble(decimalFormat.format(value));
    }

}




