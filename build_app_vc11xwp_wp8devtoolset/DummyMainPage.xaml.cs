using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Marmalade.App;
using System.Windows.Input;
using System.Threading;

namespace MarmaladeShell
{
    public partial class DummyMainPage : PhoneApplicationPage
    {
        public DummyMainPage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            ((App)Application.Current).RootFrame.Navigate(new Uri("/Marmalade.App;component/MainPage.xaml", UriKind.Relative));
        }

    }
}
