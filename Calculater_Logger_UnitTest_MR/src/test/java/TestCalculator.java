

import org.example.Calculator;
import org.example.LogLevel;
import org.example.Logger;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TestCalculator {
    Calculator c = new Calculator();
    Logger logger = Logger.getInstance();


    @Test
    void performAddition() {
        // Set log level to TRACE for detailed logging
        logger.setLoglevel(LogLevel.TRACE);

        // Log a TRACE message
        logger.log(LogLevel.TRACE, "Performing addition test.");

        c.setNum1(2.2);
        c.setNum2(3.0);
        c.setOperator("➕"); // Set the operator for addition
        assertEquals(5.2, c.performCalculations(logger));

        c.setNum1(-52.3);
        c.setNum2(25.2);
        c.setOperator("➕"); // Set the operator for addition
        assertEquals(-27.1, c.performCalculations(logger));

        c.setNum1(-3.0);
        c.setNum2(-5.2);
        c.setOperator("➕"); // Set the operator for addition
        assertEquals(-8.2, c.performCalculations(logger));

        // Log a DEBUG message
        logger.log(LogLevel.DEBUG, "Addition tests completed.");
    }

    @Test
    void performSubtraction() {
        // Set log level to TRACE for detailed logging
        logger.setLoglevel(LogLevel.TRACE);

        // Log a TRACE message
        logger.log(LogLevel.TRACE, "Performing subtraction test.");
        c.setNum1(7.);
        c.setNum2(3.);
        c.setOperator("➖"); // Set the operator for addition
        assertEquals(4, c.performCalculations(logger));

        c.setNum1(2.2);
        c.setNum2(3.);
        c.setOperator("➖"); // Set the operator for addition
        assertEquals(-0.8, c.performCalculations(logger));

        c.setNum1(100.0);
        c.setNum2(72.5);
        c.setOperator("➖"); // Set the operator for addition
        assertEquals(27.5, c.performCalculations(logger));

        // Log a DEBUG message
        logger.log(LogLevel.DEBUG, "Subtraction tests completed.");

    }

    @Test
    void performMultiplication() {
        // Set log level to TRACE for detailed logging
        logger.setLoglevel(LogLevel.TRACE);

        // Log a TRACE message
        logger.log(LogLevel.TRACE, "Performing multiplication test.");
        c.setNum1(4.2);
        c.setNum2(3.0);
        c.setOperator("✖"); // Set the operator for multiplication
        assertEquals(12.60, c.performCalculations(logger));

        c.setNum1(-4.2);
        c.setNum2(3.0);
        c.setOperator("✖"); // Set the operator for multiplication
        assertEquals(-12.60, c.performCalculations(logger));

        c.setNum1(-4.2);
        c.setNum2(-3.0);
        c.setOperator("✖"); // Set the operator for multiplication
        assertEquals(12.60, c.performCalculations(logger));

        // Log a DEBUG message
        logger.log(LogLevel.DEBUG, "Multiplication tests completed.");

    }
    @Test
    void performDivision() {
        // Set log level to TRACE for detailed logging
        logger.setLoglevel(LogLevel.TRACE);

        // Log a TRACE message
        logger.log(LogLevel.TRACE, "Performing division test.");

        c.setNum1(12.0);
        c.setNum2(3.0);
        c.setOperator("➗"); // Set the operator for Division
        assertEquals(4, c.performCalculations(logger));

        c.setNum1(-12.0);
        c.setNum2(3.0);
        c.setOperator("➗"); // Set the operator for Division
        assertEquals(-4, c.performCalculations(logger));

        c.setNum1(0.0);
        c.setNum2(3.0);
        c.setOperator("➗"); // Set the operator for Division
        assertEquals(0, c.performCalculations(logger));

        c.setNum1(3.0);
        c.setNum2(0.0);
        c.setOperator("➗"); // Set the operator for Division
        assertEquals(0, c.performCalculations(logger));

        // Log a DEBUG message
        logger.log(LogLevel.DEBUG, "Division tests completed.");

    }



}
