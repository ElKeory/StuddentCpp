using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;
using System.Text.RegularExpressions;
using System.Collections;
using System.Linq;
using System.Globalization;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters;
using System.Diagnostics.CodeAnalysis;
//using System.Runtime.Serialization.Json;
//using System.Text.Json.Serialization;
//using System.Text.Json;
//using Newtonsoft.Json;
//using JsonSerializer = Newtonsoft.Json.JsonSerializer;

namespace Lab01
{
    [DataContract]
    [XmlInclude(typeof(HourlySalary))]
    [XmlInclude(typeof(FixedSalary))]
    internal class Organisation
    {
        public List<Person> Workers { get; set; } = new List<Person>();
        public decimal AverageSalary { get; set; }
    }
    internal abstract class Person
    {
        [DataMember]
        public string SecondName { get; set; }
        [DataMember]
        public string FirstName { get; set; }
        [DataMember]
        public string MiddleName { get; set; }
        [DataMember]
        public string Birthday { get; set; }
        [DataMember]
        public string Identification { get; set; }
        [DataMember]
        public string Profession { get; set; }
        [DataMember]
        public decimal Salary { get; set; }
        public Person()
        {
            this.Profession = Profession;
            this.SecondName = SecondName;
            this.FirstName = FirstName;
            this.MiddleName = MiddleName;
            this.Birthday = Birthday;
            this.Identification = Identification;
            SalaryCalc();
        }
        //public string EditName(string Name)
        //{
        //    TextInfo EditName = CultureInfo.CurrentCulture.TextInfo;
        //    return EditName.ToTitleCase(Name);
        //}

        protected const int BonusOfProgrammer = 5000;
        protected const int BonusOfDirector = 8000;
        protected const int BonusOfAnimator = 3000;
        protected const int BonusOfTester = 6000;
        public abstract decimal SalaryCalc();
    }
    internal class HourlySalary : Person
    {
        public HourlySalary() : base() { }
        private const int RateOfProgrammer = 300;
        private const int RateOfDirector = 450;
        private const int RateOfAnimator = 270;
        private const int RateOfTester = 340;
        public override decimal SalaryCalc()
        {
            Console.WriteLine($"//{Profession}//\n");
            switch (FirstName)
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
    }
    internal class FixedSalary : Person
    {
        public FixedSalary() : base() { }
        private const int SalaryOfProgrammer = 30000;
        private const int SalaryOfDirector = 45000;
        private const int SalaryOfAnimator = 27000;
        private const int SalaryOfTester = 34000;
        public override decimal SalaryCalc()
        {
            switch(Profession)
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
                    break;;              
            }
            return Salary;
        }
    }
    internal class Program
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
        internal static void DataSeparation(string[] Separation)
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
                EditName(Separation[3].Substring(0, 1)) +
                "." + Convert.ToString(Company.Workers.Count + 1)
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
            DataSeparation(Console.ReadLine().Split(' '));          
        }
        //internal static void AddFixedSalaryWorker()
        //{
        //    Console.WriteLine("Введите ФИО, дату рождения: ");
        //    Company.Workers.Add(new FixedSalary(Console.ReadLine().Split(' ')));
        //}
        internal static void GetAllWorkers()
        {
            foreach (Person person in Company.Workers)
            {
                Console.WriteLine($"Профессия: {person.Profession}\n" +
                    $"ФИО: {person.SecondName} {person.FirstName} {person.MiddleName}\n" +
                    $"Дата рождения: {person.Birthday}\n" +
                    $"Зарплата: {person.Salary}\n" +
                    $"Идентификатор: {person.Identification}");
            }
        }
        internal static void GetFiveWorkers()
        {
            foreach (Person person in Company.Workers
                    .OrderBy(person => person.Salary)
                    .ThenBy(person => person.SecondName)
                    .ThenBy(person => person.FirstName)
                    .ThenBy(person => person.MiddleName).Take(5))
            {
                Console.WriteLine($"Профессия: {person.Profession}" +
                $"ФИО: {person.SecondName} {person.FirstName} {person.MiddleName}\n" +
                $"Дата рождения: {person.Birthday}\n" +
                $"Зарплата: {person.Salary}\n" +
                $"Идентификатор: {person.Identification}");
            }
        }
        internal static void GetThreeLastIdentification()
        {
            try
            {
                foreach (Person personId in Company.Workers
                    .OrderBy(personId => personId.Identification).TakeLast(3))
                {
                    Console.WriteLine(personId.Identification);
                }
            }
            catch
            {

            }
        }
        internal static void AddWorker()
        {
            Console.WriteLine("Добавить сотруднка с почасовой или фиксированной оплатой?\n" +
                    "1.С почасовой.\n" +
                    "2.С фиксированной.");
            switch (ResponseWorkers("1-2"))
            {
                case 1:
                    AddHourlySalaryWorker();
                    break;
                case 2:
                    //AddFixedSalaryWorker();
                    break;
            }
            Console.WriteLine("Сотрудник добавлен.\n");
        }
        internal static void ChoseTypeOfFile()
        {
            Console.WriteLine("В какой тип файл какого типа добавить список сотрудников?\n" +
                    "1. Xml\n" +
                    "2. Json\n");
            switch (ResponseChoseTypeOfFile("1-2"))
            {
                case 1:                  
                        var XmlType = new XmlSerializer(typeof(List<Person>));
                        using (var file = new FileStream("WorkersXm.xml", FileMode.OpenOrCreate))
                        {
                            XmlType.Serialize(file, Company.Workers);
                        }
                        Console.WriteLine("Данные сохранены\n");
                    break;
                case 2: Console.WriteLine("Nothing interesting\n");
                    break;
            }
            Console.WriteLine("Данные загружены в файл.\n");
        }
        internal static void WorkersSort()
        {
            Console.WriteLine("Список сотрудников отсортирован.\n");
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
                    break;
                case 5:
                    break;
                case 6:
                    ChoseTypeOfFile();
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
        internal static Organisation Company { get; set; }
        internal static void Main(string[] args)
        {
            Company = new Organisation();
            Menu();
        }
    }
}
