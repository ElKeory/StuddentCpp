using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;
using System.Text.RegularExpressions;
using System.Linq;
using System.Globalization;
using System.Runtime.Serialization;
//using System.Runtime.Serialization.Json;
//using System.Text.Json.Serialization;
//using System.Text.Json;
//using Newtonsoft.Json;
//using JsonSerializer = Newtonsoft.Json.JsonSerializer;

namespace Lab01
{
    [XmlInclude(typeof(Organisation))]
    public class Organisation
    {
        public List<Person> Workers { get; set; } = new List<Person>();
        public decimal AverageSalary { get; set; }
    }
    [XmlInclude(typeof(HourlySalary))]
    [XmlInclude(typeof(FixedSalary))]
    public abstract class Person
    {
        public string SecondName { get; set; }
        public string FirstName { get; set; }
        public string MiddleName { get; set; }
        public string Birthday { get; set; }
        public string Identification { get; set; }
        public string Profession { get; set; }
        public decimal Salary { get; set; }

        protected const int BonusOfProgrammer = 5000;
        protected const int BonusOfDirector = 8000;
        protected const int BonusOfAnimator = 3000;
        protected const int BonusOfTester = 6000;
        public abstract decimal SalaryCalc();       
    }
    public class HourlySalary : Person
    {
        public HourlySalary() {  }
        private const int RateOfProgrammer = 260;
        private const int RateOfDirector = 340;
        private const int RateOfAnimator = 200;
        private const int RateOfTester = 290;
        public override decimal SalaryCalc()
        {
            switch (Profession)
            {
                case "Программист":
                    Salary = Convert.ToDecimal(RateOfProgrammer * 20.8 * 8 + BonusOfProgrammer);                  
                    break;
                case "Директор":
                    Salary = Convert.ToDecimal(RateOfDirector * 20.8 * 8 + BonusOfDirector);
                    break;
                case "Аниматор":
                    Salary = Convert.ToDecimal(RateOfAnimator * 20.8 * 8 + BonusOfAnimator);
                    break;
                case "Тестировщик":
                    Salary = Convert.ToDecimal(RateOfTester * 20.8 * 8 + BonusOfTester);
                    break;
            }
            return Salary;
        }
        public override string ToString()
        {
            return $"Профессия: {Profession}\n" +
                    $"ФИО: {SecondName} {FirstName} {MiddleName}\n" +
                    $"Дата рождения: {Birthday}\n" +
                    $"Зарплата: {SalaryCalc()}\n" +
                    $"Идентификатор: {Identification}\n";
        }
    }
    public class FixedSalary : Person
    {
        public FixedSalary() { }
        private const int SalaryOfProgrammer = 30000;
        private const int SalaryOfDirector = 45000;
        private const int SalaryOfAnimator = 27000;
        private const int SalaryOfTester = 34000;
        public override decimal SalaryCalc()
        {
            switch (Profession)
            {
                case "Программист":
                    Salary = SalaryOfProgrammer + BonusOfProgrammer;
                    break;
                case "Директор":
                    Salary = SalaryOfDirector + BonusOfDirector;
                    break;
                case "Аниматор":
                    Salary = SalaryOfAnimator + BonusOfAnimator;
                    break;
                case "Тестировщик":
                    Salary = SalaryOfTester + BonusOfTester;
                    break; ;
            }
            return Salary;
        }
        public override string ToString()
        {
            return $"Профессия: {Profession}\n" +
                    $"ФИО: {SecondName} {FirstName} {MiddleName}\n" +
                    $"Дата рождения: {Birthday}\n" +
                    $"Зарплата: {SalaryCalc()}\n" +
                    $"Идентификатор: {Identification}\n";
        }
    }
    public class Program
    {
        internal static int ResponseMenu(string Range)
        {
            string response;
            do
            {
                response = Console.ReadLine();
            }
            while (!Regex.IsMatch(response, $@"^[{Range}]$"));
            return Convert.ToInt32(response);
        }
        internal static int ResponseWorkers(string Range)
        {
            string response;
            do
            {
                response = Console.ReadLine();
            }
            while (!Regex.IsMatch(response, $@"^[{Range}]$")) ;
            return Convert.ToInt32(response);
        }
        internal static int ResponseChoseTypeOfFile(string Range)
        {
            string response;
            do
            {
                response = Console.ReadLine();
            }
            while (!Regex.IsMatch(response, $@"^[{Range}]$"));
            return Convert.ToInt32(response);
        }
        internal static void HourlyDataSeparation(string[] Separation)
        {
            Company.Workers.Add(new HourlySalary
            {
                Profession = EditName(Separation[0]),
                SecondName = EditName(Separation[1]),
                FirstName = EditName(Separation[2]),
                MiddleName = EditName(Separation[3]),
                Birthday = EditName(Separation[4]),
                Identification = EditName(Separation[1].Substring(0, 1)) +
                EditName(Separation[2].Substring(0, 1)) +
                EditName(Separation[3].Substring(0, 1)) + "." + Convert.ToString(Company.Workers.Count + 1)
            });
        }
        internal static string EditName(string Name)
        {
            TextInfo EditName = CultureInfo.CurrentCulture.TextInfo;
            return EditName.ToTitleCase(Name);
        }
        internal static void AddHourlySalaryWorker()
        {
            Console.WriteLine("Введите: Профессию, ФИО, дату рождения: ");
            HourlyDataSeparation(Console.ReadLine().Split(' '));          
        }
        internal static void FixedDataSeparation(string[] Separation)
        {
            Company.Workers.Add(new FixedSalary
            {
                Profession = EditName(Separation[0]),
                SecondName = EditName(Separation[1]),
                FirstName = EditName(Separation[2]),
                MiddleName = EditName(Separation[3]),
                Birthday = EditName(Separation[4]),
                Identification = EditName(Separation[1].Substring(0, 1)) +
                EditName(Separation[2].Substring(0, 1)) +
                EditName(Separation[3].Substring(0, 1)) + "." + Convert.ToString(Company.Workers.Count + 1)
            });
        }
        internal static void AddFixedSalaryWorker()
        {
            Console.WriteLine("Введите: Профессию, ФИО, дату рождения: ");
            FixedDataSeparation(Console.ReadLine().Split(' '));
        }
        internal static void GetAllWorkers()
        {
            Console.Clear();
            foreach (Person person in Company.Workers)
            {
                Console.WriteLine(person.ToString());
            }
        }
        internal static void GetFiveWorkers()
        {
            Console.Clear();
            foreach (Person person in Company.Workers
                    .OrderByDescending(person => person.Salary)
                    .ThenBy(person => person.SecondName)
                    .ThenBy(person => person.FirstName)
                    .ThenBy(person => person.MiddleName).Take(5))
            {
                Console.WriteLine(person.ToString());
            }
        }
        internal static void GetThreeLastIdentification()
        {
            Console.Clear();
                foreach (Person personId in Company.Workers
                    .OrderBy(personId => personId.Identification).TakeLast(3))
                {
                    Console.WriteLine(personId.Identification);
                }
        }
        internal static void AddWorker()
        {
            Console.Clear();
            Console.WriteLine("Список доступных профессий:\n" +
                        "Программист\n" +
                        "Директор\n" +
                        "Аниматор\n" +
                        "Тестировщик\n\n" +
                        "Добавить сотруднка с почасовой или фиксированной оплатой?\n" +
                        "1.С почасовой.\n" +
                        "2.С фиксированной.");
            switch (ResponseWorkers("1-2"))
            {
                case 1:
                    AddHourlySalaryWorker();
                    break;
                case 2:
                    AddFixedSalaryWorker();
                    break;
            }
            Console.WriteLine("Сотрудник добавлен.\n");
        }
        internal static void ChoseTypeOfFileInput()
        {
            Console.Clear();
            Console.WriteLine("Из файла какого типа взять список сотрудников?\n" +
                    "1. Xml\n" +
                    "2. Json");
            switch (ResponseChoseTypeOfFile("1-2"))
            {
                case 1:
                    XmlSerializer XmlInput = new XmlSerializer(typeof(Organisation));
                    using (FileStream Input = new FileStream("Workersxm.xml", FileMode.Open))
                    {
                        Company = XmlInput.Deserialize(Input) as Organisation;
                        Input.Close();
                    }
                    break;
                case 2:
                    Console.WriteLine("Nothing interesting\n");
                    break;
            }
            Console.WriteLine("Данные загружены\n");
        }
        internal static void ChoseTypeOfFileOutput()
        {
            Console.Clear();
            Console.WriteLine("В какой тип файл какого типа добавить список сотрудников?\n" +
                    "1. Xml\n" +
                    "2. Json");
            switch (ResponseChoseTypeOfFile("1-2"))
            {
                case 1:
                    XmlSerializer XmlOutput = new XmlSerializer(typeof(Organisation));
                    using (FileStream Output = new FileStream("Workersxm.xml", FileMode.OpenOrCreate))
                    {
                        XmlOutput.Serialize(Output, Company);
                        Output.Flush();
                        Output.Close();
                    }
                    break;
                case 2: Console.WriteLine("Nothing interesting\n");
                    break;
            }
            Console.WriteLine("Данные добавлены в файл.\n");
        }
        internal static void WorkersSort()
        {
            Console.Clear();
            Console.WriteLine("Список сотрудников отсортирован.\n"); //!!!!!!!!!!!!!!!!!!!
        }
        internal static void GetAverangeSalary()
        {
            Console.Clear();
        }
        internal static void Menu()
        {
            Console.WriteLine("Меню:\n" +
            "1. Упорядочивание сотрудников.\n" +
            "2. Вывести первые 5 имен работников.\n" +
            "3. Вывести последние 3 идентификатора работников.\n" +
            "4. Показать среднюю заработную плату сотрудников.\n" +
            "5. Взять список сотрудников из файла.\n" +
            "6. Записать список сотрудников в файл.\n" +
            "7. Добавить сотрудников.\n" +
            "8. Вывести сотрудников.\n" +
            "9. Выход из программы.");
            switch (ResponseMenu("1-9"))
            {
                case 1:
                    WorkersSort();
                    Menu();
                    break;
                case 2:
                    GetFiveWorkers();
                    Menu();
                    break;
                case 3:
                    GetThreeLastIdentification();
                    Menu();
                    break;
                case 4:
                    GetAverangeSalary();
                    Menu();
                    break;
                case 5:
                    ChoseTypeOfFileInput();
                    Menu();
                    break;
                case 6:
                    ChoseTypeOfFileOutput();
                    Menu();
                    break;
                case 7:
                    AddWorker();
                    Menu();
                    break;               
                case 8:
                    GetAllWorkers();
                    Menu();
                    break;
                case 9:
                    System.Environment.Exit(0);
                    break;
            }
        }
        public static Organisation Company { get; set; }
        internal static void Main(string[] args)
        {
            Company = new Organisation();
            Menu();
        }
    }
}
