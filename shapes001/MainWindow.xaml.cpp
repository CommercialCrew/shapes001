// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;
struct winrt::Windows::UI::Color col = winrt::Microsoft::UI::Colors::Green();
struct winrt::Windows::UI::Color col2 = winrt::Microsoft::UI::Colors::Red();
struct winrt::Windows::UI::Color col3 = winrt::Microsoft::UI::Colors::Cornsilk();
struct winrt::Windows::UI::Color col4 = winrt::Microsoft::UI::Colors::Aquamarine();


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::shapes001::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }


}


void winrt::shapes001::implementation::MainWindow::CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    CanvasControl canvas = sender.as<CanvasControl>();
    px = e.GetCurrentPoint(canvas).Position().X;
    py = e.GetCurrentPoint(canvas).Position().Y;
    canvas.Invalidate();
}


void winrt::shapes001::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
    args.DrawingSession().DrawEllipse(50, 75, 80, 60, col, 8);
    args.DrawingSession().DrawCircle(300, 150, 100, col2, 10);
    args.DrawingSession().DrawRectangle(200, 400, 50 ,60,col3, 12);
    args.DrawingSession().DrawLine(50, 120, 600, 800, col4, 6);
    args.DrawingSession().DrawTextW(L"S A M P L E T E X T", 450, 450, winrt::Microsoft::UI::Colors::DarkOrchid());
}
