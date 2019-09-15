package package1;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class SeleniumClass {
//driver executable path for eclipse
static
{
System.setProperty("webdriver.chrome.driver", "./driver/chromedriver.exe");   //chrome driver
}

public static void main(String[] args) throws InterruptedException{
//open the browser
WebDriver driver = new ChromeDriver();

//Maximize the browser
driver.manage().window().maximize();

//Enter the URl

driver.get("http://www.gmail.com");
driver.findElement(By.xpath("//input[@name='identifier']")).sendKeys("mitselenium01@gmail.com");
driver.findElement(By.xpath("//span[text()='Next']")).click();
Thread.sleep(2000);
driver.findElement(By.xpath("//input[@type='password']")).sendKeys("selenium123");
driver.findElement(By.xpath("//span[text()='Next']")).click();
}
}
