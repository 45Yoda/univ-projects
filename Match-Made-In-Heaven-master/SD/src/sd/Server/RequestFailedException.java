/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

/**
 *
 * @author Rui_vieira
 */
public class RequestFailedException extends Exception {
    public RequestFailedException(String message) {
        super(message);
    }
    
}