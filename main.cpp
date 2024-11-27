#include <QApplication>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include "qcustomplot/qcustomplot.h"
#include <QDebug>

// Function to create and display the plot
void makePlot() {
    QFile file("data");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file!";
        return;
    }

    QVector<double> xData, yData;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        if (fields.size() >= 2) {
            xData.append(fields[0].toDouble());
            yData.append(fields[1].toDouble());
        }
    }

    auto customPlot = new QCustomPlot(); // Instantiate QCustomPlot

    // Create a scatter plot
    customPlot->addGraph();
    customPlot->graph(0)->setData(xData, yData);

    // Disable line connection between points
    customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);

    // Set scatter style to dots
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));

    // Set axes ranges dynamically based on data
    customPlot->xAxis->setRange(*std::min_element(xData.begin(), xData.end()),
                                *std::max_element(xData.begin(), xData.end()));
    customPlot->yAxis->setRange(*std::min_element(yData.begin(), yData.end()),
                                *std::max_element(yData.begin(), yData.end()));

    customPlot->replot();
    customPlot->resize(800, 600);
    customPlot->show();
}
/**

QCPScatterStyle::ssCross: Cross shape.
QCPScatterStyle::ssCircle: Hollow circle.
QCPScatterStyle::ssStar: Star shape.
QCPScatterStyle::ssDiamond: Diamond shape.

 * **/

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Call the function to create the plot
    makePlot();

    return app.exec();
}
