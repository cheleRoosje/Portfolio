package org.example;


import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class Logger {
    private static Logger _instance;
    private LogLevel loglevel;
    private List<String> logs;
    private PrintWriter fileWriter;

    public Logger(){
        // make INFO default that shows
        loglevel = LogLevel.INFO;
        //save to an array list so it can be logged all at once
        logs = new ArrayList<>();
        try {
            fileWriter = new PrintWriter(new FileWriter("logger.log"));
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Log an error message
    public void logError(String errorMessage) {
        String logMessage = String.format("[ERROR] [%s] %s", LocalDateTime.now(), errorMessage);
        System.err.println(logMessage);  // Log to standard error (stderr)
        fileWriter.println(logMessage);
        fileWriter.flush();
        logs.add(logMessage);
    }

    public static Logger getInstance(){
        if(_instance == null){
            synchronized (Logger.class){
                //check to see if null (not created) if null will create one
                if(_instance == null)
                    _instance = new Logger();
            }
        }
        //return the instance
        return _instance;
    }

    //Set the log level
    public void setLoglevel(LogLevel level) {
        loglevel = level;
    }
    // Log a message with the specified level
    public void log(LogLevel level, String message){
        if (level.ordinal() >= loglevel.ordinal()) {
            //System.out.println(message);
            String log = String.format("[%s] [%s] %s", level, LocalDateTime.now(), message);
            System.out.println(log);
            fileWriter.println(log);
            fileWriter.flush();
        }
        logs.add(String.format("[%s] [%s] %s", level, LocalDateTime.now(), message));
    }
    //Display all logged messages
    public void displayLogs(){
        for (String log : logs) {
            System.out.println(log);
        }
    }



    // Add a method to get logs as a List
    public List<String> getLogs() {
        return logs;
    }
}



