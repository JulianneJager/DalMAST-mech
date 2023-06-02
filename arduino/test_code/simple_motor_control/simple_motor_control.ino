// Send PWM signal to motor
// Rudder motor link: https://www.aliexpress.com/item/4001029200657.html?spm=a2g0o.productlist.0.0.24fd5ccdBSWY9N&algo_pvid=657bc0ff-8ec7-4c46-9f53-20477a94550b&aem_p4p_detail=20220529191416702657118893810028317413&algo_exp_id=657bc0ff-8ec7-4c46-9f53-20477a94550b-23&pdp_ext_f=%7B%22sku_id%22%3A%2210000013601759629%22%7D&pdp_npi=2%40dis%21CAD%21%2143.98%21%21%2116.69%21%21
// Red wire: Power in to motor
// Black wire: motor ground (use same ground as arduino ground)
// Blue wire: PWM signal

int pinPWM = 2;         // pin to set speed of motor

void setup() {
  pinMode(pinPWM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(pinPWM,127);
}
