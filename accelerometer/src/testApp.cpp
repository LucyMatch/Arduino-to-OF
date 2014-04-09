#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    /*Prints out the available serial devices*/
    serial.enumerateDevices();
    //establish connection to ardy at baud 9600
	serial.setup("/dev/tty.usbmodem1411", 9600);
    
    circleX = 100;
    circleY = 100;
    circleR = 100;

}

//--------------------------------------------------------------
void testApp::update(){
    
    //how many bytes are available in the serial port
    //can change the "0" to something else if we know how long the message is in bytes and only want to recieve it after it is complete
    
    if(serial.available() > 0) {
        
        //Read all the bytes from the Serial port into the buffer object
        //Now the application can parse the data received from the Serial port and use it
        //because of the Ardy sketch the info should come in like this X0.8Y10.7Z0.6
        //buffer[0] = X
        //buffer[1] = X value
        //buffer[2] = Y
        //buffer[3] = Y value
        //buffer[4] = Z
        //buffer[5] = Z value
        serial.readBytes(buffer, 6);
        
        if(buffer[0] == 'X') {
            cout << "X= " << buffer[1] << endl;
            //ofBackground(buffer[1],buffer[3],buffer[5]);
		}
        if(buffer[2] == 'Y') {
			cout << "Y= " << buffer[3] << endl;
            //ofBackground(buffer[1],buffer[3],buffer[5]);
		}
        if(buffer[4] == 'Z') {
			cout << "Z= " << buffer[5] << endl;
            //ofBackground(buffer[1],buffer[3],buffer[5]);
            circleR = (5 * buffer[5]);
		}
        
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(circleX, circleY, circleR);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
