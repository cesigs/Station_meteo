void lum(){
    Serial.print("Brightness = ");
    Serial.print(analogRead(A0));
    Serial.println(" lumen");
}