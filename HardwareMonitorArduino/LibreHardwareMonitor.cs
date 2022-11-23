using System;
using LibreHardwareMonitor.Hardware;


namespace HardwareMonitorArduino
{
    public class LibreHardwareMonitorVisitor : IVisitor 
	{ 
		private Computer computer { get; set; }
		public LibreHardwareMonitorVisitor()
        {
			Init();
        }
		public void Init(Computer computer = null)
        {
			if (computer == null)
            {
				computer = new Computer
				{
					IsCpuEnabled = true,
					IsGpuEnabled = true,
					IsMemoryEnabled = true,
					IsMotherboardEnabled = true,
					IsNetworkEnabled = true,
					IsStorageEnabled = true,

				};
				computer.Open();
				computer.Accept(this);
			} else
            {
				computer.Open();
            }
			
			

			foreach (IHardware hardware in computer.Hardware) 
			{
				if (hardware.HardwareType == HardwareType.Psu)
                {
					Console.WriteLine("Hardware: {0}", hardware.Name);

					foreach (IHardware subhardware in hardware.SubHardware)
					{
						Console.WriteLine("\tSubhardware: {0}", subhardware.Name);

						foreach (ISensor sensor in subhardware.Sensors)
						{
							Console.WriteLine("\t\tSensor: {0}, value: {1}", sensor.Name, sensor.Value);
						}
					}

					foreach (ISensor sensor in hardware.Sensors)
					{
						Console.WriteLine("\tSensor: {0}, value: {1}", sensor.Name, sensor.Value);
					}
				}
			}
			computer.Close();
        }
		public void VisitComputer(IComputer computer)
        {
			computer.Traverse(this);
        }
		public void VisitHardware(IHardware hardware)
        {
			hardware.Update();
			foreach(IHardware subHardware in hardware.SubHardware)
            {
				subHardware.Accept(this);
            }
        }
		public void VisitSensor(ISensor sensor)
        {

        }

		public void VisitParameter(IParameter parameter)
        {

        }

	}

}
public class Class1
{
	public Class1()
	{
	}
}
