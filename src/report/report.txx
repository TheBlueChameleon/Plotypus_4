#ifndef REPORT_TXX
#define REPORT_TXX

namespace Plotypus
{
    template<TerminalInfoProviderType T>
    T& Report::installTerminal()
    {
        std::shared_ptr<TerminalInfoProvider> newProvider(new T());
        std::shared_ptr<Persistable> newPersistable = std::static_pointer_cast<Persistable>(newProvider);
        if (tip)
        {
            std::shared_ptr<Persistable> oldPersistable = std::static_pointer_cast<Persistable>(tip);
            scriptFile.replaceSubscriber(oldPersistable, newPersistable);
        }
        else
        {
            scriptFile.addSubscriber(newPersistable);
        }

        tip = newProvider;
        const auto pathToOutputFile = getDerivedPath(T::getDefaultExtension());
        tip->setPath(pathToOutputFile);
    }

    template<TerminalInfoProviderType T>
    T& Report::getTerminal()
    {
        if (!tip)
        {
            throw InvalidTypeError("No TerminalInfoProvider installed");
        }

        std::shared_ptr<T> typedTip = std::dynamic_pointer_cast<T>(tip);
        if (typedTip)
        {
            return *typedTip;
        }
        else
        {
            throw InvalidTypeError("Currently installed TerminalInfoProvider is of type '" + tip->getInstanceName() + "', but a '" + T::getTypeName() + "' was requested.");
        }
    }

    template<PersistableSPType T>
    void Report::addSubscriber(T& subscriber)
    {
        auto ptr = std::static_pointer_cast<Persistable>(subscriber.getSharedPtr());
        scriptFile.addSubscriber(ptr);
    }
}
#endif // REPORT_TXX
