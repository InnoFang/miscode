package io.innofang.gsuploadingfiles.storage;

/**
 * Created by Inno Fang on 2018/4/23.
 */
public class StorageFileNotFoundException extends StorageException {
    public StorageFileNotFoundException(String message) {
        super(message);
    }

    public StorageFileNotFoundException(String message, Throwable cause) {
        super(message, cause);
    }
}
