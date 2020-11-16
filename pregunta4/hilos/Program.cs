using System;
using System.Threading;

// Simple threading scenario:  Start a static method running
// on a second thread.
public class ThreadExample {
    //El método ThreadProc se llama cuando se inicia el hilo.
    
    // el resto de su tiempo se corta cada vez, y luego termina.
      
    public  static void ThreadProc() {
    	int steps=100000;
    	double sum=0;
    	double pi=0;
    	double step=1.0/(steps);
    	double x=0;
        for (int i = 0; i < steps; i++) {
    		x=(i+0.5)*step;
    		sum=sum+4.0/(1.0+x*x);
           
        }
    	pi=step*sum;
    	Console.WriteLine(pi);
    	//Ceda el resto del tiempo.
    	Thread.Sleep(0);
    } 

    public static void Main() {
        
      
        Thread t = new Thread(new ThreadStart(ThreadProc));
        t.Start();
        t.Join();
        Console.WriteLine("Press Enter to end program.");
        Console.ReadLine();
    }
}