package io.innofang.gsuploadingfiles.storage;

import org.springframework.boot.context.properties.ConfigurationProperties;

/**
 * Created by Inno Fang on 2018/4/23.
 */

@ConfigurationProperties(value = "storage")
public class StorageProperties {

    /**
     * Folder location for storing files
     */
    private String location = "upload-dir";

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }
}
