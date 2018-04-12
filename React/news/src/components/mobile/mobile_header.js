/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react'
export default class MobileHeader extends React.Component {
    render() {
        return (
            <div id="mobileheader">
                <header>
                    <img src={require('../../images/logo.png')} alt="logo"/>
                    <span>ReactNews</span>
                </header>
            </div>
        )
    }
}