function Copy-Links {
    $url = 'https://myrient.erista.me/files/No-Intro/Nintendo%20-%20Nintendo%20Entertainment%20System%20(Headered)/'
    $response = Invoke-WebRequest $url
    $links = $response.Links | Where-Object { $_.href -like '*.zip' } | Select-Object href
    $links | ForEach-Object {
        $fullLink = ($url + $_.href).Replace(' ', '%20')
        Write-Host $fullLink
        $fullLink | Out-File -FilePath links.txt -Append
    }
    $numLinks = $links.Count
    Write-Host "================ Copiado $numLinks URL(s) para o arquivo links.txt. ================"
    Start-Sleep -Seconds 5
}

function Download-Files {
    $links = Get-Content links.txt
    $folderBrowser = New-Object System.Windows.Forms.FolderBrowserDialog
    $folderBrowser.Description = "Selecione a pasta onde os arquivos serão salvos"
    $result = $folderBrowser.ShowDialog()
    if ($result -eq 'OK') {
        $folderPath = $folderBrowser.SelectedPath
        $url = $links[0] # assume que todas as URLs são do mesmo tipo
        if ($url.Contains("nes")) {
            $romType = "NES_roms"
        } elseif ($url.Contains("genesis")) {
            $romType = "GENESIS_roms"
        } elseif ($url.Contains("mastersystem")) {
            $romType = "MASTER_roms"
        } else {
            $romType = "ROMs"
        }
        $path = Join-Path -Path $folderPath -ChildPath $romType
        New-Item -ItemType Directory -Path $path -ErrorAction SilentlyContinue | Out-Null
        $wc = New-Object System.Net.WebClient
        $wc.Headers.Add('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36')
        foreach ($link in $links) {
            $filename = $link.Substring($link.LastIndexOf('/') + 1)
            $filename = $filename.Replace('%20', ' ')
			$filename = $filename.Replace("%27", "'")
			$filename = $filename.Replace("&amp;", "")
            $filepath = Join-Path -Path $path -ChildPath $filename
            Write-Host "Baixando arquivo: $filename"
            $wc.DownloadFile($link, $filepath)
            Rename-Downloaded-Files $filepath
        }
        Write-Host "Download concluído!"
        Start-Sleep -Seconds 20
    }
}


function Rename-Downloaded-Files {
    param (
        [string]$FilePath
    )

    $NewFileName = $FilePath -replace '%20', ' ' -replace "%27", "'"

    Rename-Item -Path $FilePath -NewName $NewFileName
}


function Show-Menu {
    param (
        [string]$Title = 'Menu:'
    )
    cls
    Write-Host "================ $Title ================"
    Write-Host "1: Copiar links"
    Write-Host "2: Baixar arquivos"
    Write-Host "3: Sair"
}

do {
    Show-Menu
    $input = Read-Host "Selecione uma opção"
    switch ($input) {
        '1' {
            $dlg = New-Object System.Windows.Forms.SaveFileDialog
            $dlg.Title = "Selecione um arquivo para salvar os links"
            $dlg.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"
            $dlg.DefaultExt = "txt"
            $dlg.InitialDirectory = [System.Environment]::GetFolderPath('Desktop')
            $result = $dlg.ShowDialog()
            if ($result -eq [System.Windows.Forms.DialogResult]::OK) {
                Copy-Links
            }
        }
        '2' {

            Download-Files
        }
        '3' {
            break
        }
    }
} while ($input -ne '3')
