using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using OpenHardwareMonitor.Hardware;
using HardwareMonitorArduino;

namespace Arduino_Controll
{
    public partial class Form1 : Form
    {
        static string data;
        Computer c = new Computer() { };

        float value1, value2;

        private SerialPort port = new SerialPort();
        public Form1()
        {
            InitializeComponent();
            Init();
        }


        private void Init()
        {
            try
            {
                notifyIcon1.Visible = false;
                port.Parity = Parity.None;
                port.StopBits = StopBits.One;
                port.DataBits = 8;
                port.Handshake = Handshake.None;
                port.RtsEnable = true;
                string[] ports = SerialPort.GetPortNames();
                foreach (string port in ports)
                {
                    Console.WriteLine(port);
                    comboBox2.Items.Add(port);
                }
                port.BaudRate = 9600;
                var visitor = new LibreHardwareMonitorVisitor();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void button3_Click_1(object sender, EventArgs e)
        {
            try
            {
                port.Write("DIS*");
                port.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            label2.Text = "Disconnected";
            timer1.Enabled = false;
            toolStripStatusLabel1.Text = "Connect to Arduino...";
            data = "";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Status();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            c.Open();
            c.MainboardEnabled = true;
            c.Close();
            c.Open();
            c.MainboardEnabled = true;
            c.GPUEnabled = true;
            c.CPUEnabled = true;
            c.RAMEnabled = true;
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            if (FormWindowState.Minimized == this.WindowState)
            {
                notifyIcon1.Visible = true;
                try
                {
                    notifyIcon1.ShowBalloonTip(500, "Arduino", toolStripStatusLabel1.Text, ToolTipIcon.Info);

                }
                catch (Exception ex)
                {

                }
                this.Hide();
            }


        }


        private void notifyIcon1_DoubleClick(object sender, EventArgs e)
        {

            this.Show();
            this.WindowState = FormWindowState.Normal;
            notifyIcon1.Visible = false;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (!port.IsOpen)
                {
                    port.PortName = comboBox2.Text;
                    port.Open();
                    timer1.Interval = Convert.ToInt32(comboBox1.Text);
                    timer1.Enabled = true;
                    toolStripStatusLabel1.Text = "Sending data...";
                    label2.Text = "Connected";
                    Status();
                    timer1.Start();
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void toolStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void Status()
        {
            
            //foreach (var component in c.Hardware)
            //{
            //    var x = c.Hardware;
            //    var y = c.GetReport();
            //    if (component.HardwareType == HardwareType.GpuNvidia)
            //    {
            //        component.Update();
            //        foreach (var sensor in component.Sensors)
            //            if (sensor.SensorType == SensorType.Temperature)
            //            {

            //                value1 = sensor.Value.GetValueOrDefault();
            //            }

            //    }
            //    else if (component.HardwareType == HardwareType.GpuAti)
            //    {
            //        component.Update();
            //        value1 = component.Sensors.First(s => s.SensorType == SensorType.Temperature).Value.GetValueOrDefault();
            //    }

            //    if (component.HardwareType == HardwareType.CPU)
            //    {
            //            component.Update();
            //        foreach (var sensor in component.Sensors)
            //            if (sensor.SensorType == SensorType.Temperature)
            //            {
            //                value2 = sensor.Value.GetValueOrDefault();

            //            }

            //    }

            //}
            //try
            //{
            //    port.Write(value1 + "*" + value2 + "#");
            //}
            //catch (Exception ex)
            //{
            //    timer1.Stop();
            //    MessageBox.Show(ex.Message);
            //    toolStripStatusLabel1.Text = "Arduino's not responding...";
            //}
        }

    }
}



