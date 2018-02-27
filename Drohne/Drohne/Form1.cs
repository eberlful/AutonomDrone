using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Drohne
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            getAvailablePorts();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label17_Click(object sender, EventArgs e)
        {

        }

        /*
         * Aktuallisiert die verfügbaren USB-Ports
         */
        private void getAvailablePorts()
        {
            String[] ports = SerialPort.GetPortNames();
            portList.Items.AddRange(ports);
        }

        /*
         * Schreibt den übergebenen String an den ausgwählten Port
         */
        private void writeSerialString(String value)
        {
            try
            {
                port.WriteLine(value);
            }
            catch (Exception ex)
            {
                txtArduinoLog.AppendText(ex.ToString());
            }
        }

        private String readSerialString()
        {
            String value = "";
            try
            {
                value = port.ReadLine();
            }
            catch (Exception ex)
            {
                txtArduinoLog.AppendText(ex.ToString());
            }

            return value;
        }

        SerialPort port = new SerialPort();
        private void btnVerbindenArduino_Click(object sender, EventArgs e)
        {
            try
            {
                if (portList.Text == "" || baudList.Text == "")
                {
                    txtArduinoLog.Text = "Bitte Port und Baudrate wählen";
                }
                else
                {  
                    port.PortName = portList.Text;
                    port.BaudRate = Convert.ToInt32(baudList.Text);
                    port.Open();
                    Thread thread1 = new Thread(new ThreadStart(thread1Function));
                    progressBar1.Value = 100;
                }
            }
            catch (Exception ex)
            {
                txtArduinoLog.Text = ex.ToString();
            }
        }

        private void thread1Function()
        {
            try
            {
                String serialIn;
                serialIn = readSerialString();
                txtArduinoLog.AppendText(serialIn);
            }
            catch (Exception ex)
            {
                txtArduinoLog.AppendText(ex.ToString());
            }
        }

        private void btnArduinoAbbrechen_Click(object sender, EventArgs e)
        {
            port.Close();
            progressBar1.Value = 0;
        }
    }
}
