package com.mycompany.operator;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
 
public class Main
{
    public static void main(String[] args) {
        String expression = "4 * 5";
 
        // Get JavaScript engine
        ScriptEngine engine = new ScriptEngineManager().getEngineByExtension("js");
 
        try {
            // Evaluate the expression
            Object result = engine.eval(expression);
 
            System.out.println(expression + " = " + result);
        }
        catch (ScriptException e) {
            // Something went wrong
            e.printStackTrace();
        }
    }
}