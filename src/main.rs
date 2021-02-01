use qt_widgets::QApplication;

fn main() {
    QApplication::init(|_| unsafe {
        QApplication::exec()
    })
}
