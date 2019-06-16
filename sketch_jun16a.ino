const int flamePin = 8; //设置火焰传感器的数字引脚为8
const int ledPin = 13; //设置LED灯的数字引脚为13
const int buzzerPin=7;  //设置蜂鸣器的数字引脚为7

//状态初始化
void setup()
{
  pinMode(flamePin,INPUT);//将8号引脚设置为输入信号
  pinMode(ledPin,OUTPUT);//将13号引脚设置为输出信号
  pinMode(buzzerPin,OUTPUT);//将7号引脚设置为输出信号
  Serial.begin(9600);//设置波特率为9600
}

//循环执行
void loop()
{
  //读取火焰传感器的数字输出，高电平表示“1”，低电平表示“0”，以布尔值的形式储存在news变量中；
  boolean news = digitalRead(flamePin);
  if(news == 0)//感应到火焰！
  {
    Serial.println("Flame!");//串口监控器显示“Flame！”
    digitalWrite(ledPin,HIGH);//将13号数字引脚的输出设置为高电平，LED灯点亮
    tone(7,320,200);//将7号数字引脚的输出设置为320Hz频率，持续时间200毫秒，蜂鸣器触发
    delay(1000);//停留1000毫秒
    digitalWrite(ledPin,LOW);//将13号数字引脚的输出设置为低电平，LED灯熄灭
    noTone(7);//

  }
  else
  {
    Serial.println("No Flame !");//串口监控器显示“flame!” 
    digitalWrite(ledPin, LOW);//将13号数字引脚的输出设置为低电平，LED灯熄灭
    digitalWrite(buzzerPin, HIGH);//将7号数字引脚的输出设置为高电平，蜂鸣器关闭
  }
  delay(500); //停留500毫秒，进行下一次循环判断火焰传感器是否触发
}
