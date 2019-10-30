```
QFileInfo fileInfo(recordedVideoFilePath_);
QString recordedFileName = fileInfo.fileName();

QDir containerFolderPath = fileInfo.dir();
containerFolderPath.setNameFilters(QStringList() << "*.*");
containerFolderPath.setFilter(QDir::Files);

for (auto &dirFile : containerFolderPath.entryList()) {
    if (recordedFileName == dirFile && remainLatestRecordedFile)
        continue;
    containerFolderPath.remove(dirFile);
```
