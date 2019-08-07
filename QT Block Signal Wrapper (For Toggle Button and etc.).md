# QT Block Signal Wrapper
    template<class T> class Blocker {
        T *blocked;
        bool previous;
    public:
        Blocker(T *blocked)
            : blocked(blocked),
              previous(blocked->blockSignals(true)) {}
        ~Blocker() { blocked->blockSignals(previous); }
        T *operator->() { return blocked; }
    };

- Use Function
    template<class T> inline Blocker<T> whileBlocking(T *blocked) {
        return Blocker<T>(blocked);
    }
- Usage
    whileBlocking(checkBox)->setChecked(true);
    
https://stackoverflow.com/questions/3556687/prevent-firing-signals-in-qt
